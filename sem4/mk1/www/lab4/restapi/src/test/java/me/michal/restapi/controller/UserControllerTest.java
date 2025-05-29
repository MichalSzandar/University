package me.michal.restapi.controller;

import me.michal.restapi.model.User;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.AutoConfigureMockMvc;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.http.MediaType;
import org.springframework.security.test.context.support.WithMockUser;
import org.springframework.test.web.servlet.MockMvc;
import com.fasterxml.jackson.databind.ObjectMapper;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.*;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.*;

@SpringBootTest
@AutoConfigureMockMvc
public class UserControllerTest {
    @Autowired
    private MockMvc mockMvc;
    @Autowired
    private ObjectMapper objectMapper;

    @Test
    @DisplayName("Should return list of users")
    @WithMockUser(roles = "ADMIN")
    void shouldReturnUsers() throws Exception {
        mockMvc.perform(get("/users"))
                .andExpect(status().isOk())
                .andExpect(jsonPath("$").isArray());
    }

    @Test
    @DisplayName("Should create user")
    @WithMockUser(roles = "ADMIN")
    void shouldCreateProduct() throws Exception {
        User user = User.builder()
                .username("Test user")
                .password("Test password")
                .build();

        mockMvc.perform(post("/users")
                .contentType(MediaType.APPLICATION_JSON)
                .content(objectMapper.writeValueAsString(user)))
                .andExpect(status().isCreated())
                .andExpect(jsonPath("$.id").exists());
    }

    @Test
    @DisplayName("Should return 404 for non-existent product")
    @WithMockUser(roles = "ADMIN")
    void shouldReturn404ForNonExistentProduct() throws Exception {
        mockMvc.perform(get("/users/99999"))
                .andExpect(status().isNotFound());
    }
}
