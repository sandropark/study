package com.sandro.springbatch.job.player;

import com.sandro.springbatch.BatchTestConfig;
import com.sandro.springbatch.core.service.PlayerSalaryService;
import com.sandro.springbatch.job.AdvancedJopConfig;
import org.junit.jupiter.api.Test;
import org.springframework.batch.core.ExitStatus;
import org.springframework.batch.core.JobExecution;
import org.springframework.batch.test.JobLauncherTestUtils;
import org.springframework.batch.test.context.SpringBatchTest;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.ActiveProfiles;
import org.springframework.test.context.ContextConfiguration;

import static org.assertj.core.api.Assertions.assertThat;

@ActiveProfiles("test")
@ContextConfiguration(classes = {FlatFileJobConfig.class, BatchTestConfig.class, PlayerSalaryService.class})
@SpringBatchTest
@SpringBootTest
class FlatFileJobConfigTest {

    @Autowired
    JobLauncherTestUtils jobLauncherTestUtils;

    @Test
    void test() throws Exception {
        JobExecution execution = jobLauncherTestUtils.launchJob();

        assertThat(execution.getExitStatus()).isEqualTo(ExitStatus.COMPLETED);
    }
}