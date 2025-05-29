package me.michal.restapi.controller;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.AutoConfigureMockMvc;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.web.servlet.MockMvc;

import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.get;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.status;

@SpringBootTest
@AutoConfigureMockMvc
class SecurityTest {
    @Autowired
    private MockMvc mockMvc;

    @Test
    @DisplayName("Should forbid access to /users for unauthenticated user")
    void shouldForbidAccessToUsers() throws Exception {
        mockMvc.perform(get("/users"))
                .andExpect(status().isForbidden());
    }
}