package com.sandro.springbatch.job;

import com.sandro.springbatch.job.validator.LocalDateParameterValidator;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.batch.core.*;
import org.springframework.batch.core.configuration.annotation.JobBuilderFactory;
import org.springframework.batch.core.configuration.annotation.JobScope;
import org.springframework.batch.core.configuration.annotation.StepBuilderFactory;
import org.springframework.batch.core.configuration.annotation.StepScope;
import org.springframework.batch.core.launch.support.RunIdIncrementer;
import org.springframework.batch.core.step.tasklet.Tasklet;
import org.springframework.batch.repeat.RepeatStatus;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import java.time.LocalDate;

@Slf4j
@RequiredArgsConstructor
@Configuration
public class AdvancedJopConfig {
    private final JobBuilderFactory jobBuilderFactory;
    private final StepBuilderFactory stepBuilderFactory;
    private final String parameterName = "targetDate";

    @Bean
    public Job advancedJob(JobExecutionListener jobExecutionListener, Step advancedStep) {
        return jobBuilderFactory.get("advancedJob")
                .incrementer(new RunIdIncrementer())
                .validator(new LocalDateParameterValidator(parameterName))
                .listener(jobExecutionListener)
                .start(advancedStep)
                .build();
    }

    @JobScope
    @Bean
    public JobExecutionListener jobExecutionListener() {
        return new JobExecutionListener() {
            @Override
            public void beforeJob(JobExecution jobExecution) {
                log.info("[JobExecutionListener#beforeJob] jobExecution is {}", jobExecution.getStatus());
            }

            @Override
            public void afterJob(JobExecution jobExecution) {
//                log.info("[JobExecutionListener#afterJob] jobExecution is {}", jobExecution.getStatus());
                if (jobExecution.getStatus() == BatchStatus.FAILED) // 상태에 따라서 원하는 작업을 수행할 수 있다.
                    log.error("[JobExecutionListener#afterJob] jobExecution is Failed");
            }
        };
    }

    @JobScope
    @Bean
    public Step advancedStep(Tasklet advancedTasklet) {
        return stepBuilderFactory.get("advancedStep")
                .tasklet(advancedTasklet)
                .build();
    }


    @StepScope
    @Bean
    public Tasklet advancedTasklet(@Value("#{jobParameters['" + parameterName + "']}") String targetDate) {
        return (contribution, chunkContext) -> {
            log.info("[AdvancedJobConfig] JobParameter - targetDate = {}", targetDate);
            LocalDate executionDate = LocalDate.parse(targetDate);
            if (executionDate.isBefore(LocalDate.of(2021, 01, 02)))
                throw new RuntimeException("에러 발생");
            log.info("[AdvancedJobConfig] excuted advancedTasklet");
            return RepeatStatus.FINISHED;
        };
    }

}
