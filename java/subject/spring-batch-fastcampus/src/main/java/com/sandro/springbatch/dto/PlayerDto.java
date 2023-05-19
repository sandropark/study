package com.sandro.springbatch.dto;

import lombok.Data;

@Data
public class PlayerDto {
    private String ID;
    private String lastName;
    private String firstName;
    private String position;
    private int birthYear;
    private int debutYear;

    public PlayerSalaryDto toSalaryDto(int salary) {
        return PlayerSalaryDto.builder()
                .ID(ID)
                .lastName(lastName)
                .firstName(firstName)
                .position(position)
                .birthYear(birthYear)
                .debutYear(debutYear)
                .salary(salary)
                .build();
    }
}
