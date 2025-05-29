package me.michal.restapi.controller;

import me.michal.restapi.model.Product;
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
class ProductControllerTest {

    @Autowired
    private MockMvc mockMvc;
    @Autowired
    private ObjectMapper objectMapper;

    @Test
    @DisplayName("Should return paginated products")
    void shouldReturnPaginatedProducts() throws Exception {
        mockMvc.perform(get("/products?page=0&size=2"))
                .andExpect(status().isOk())
                .andExpect(jsonPath("$.content").exists());
    }

    @Test
    @DisplayName("Should create product")
    @WithMockUser(roles = "ADMIN")
    void shouldCreateProduct() throws Exception {
        Product product = Product.builder()
                .name("Test Product")
                .description("Test Description")
                .build();

        mockMvc.perform(post("/products")
                .contentType(MediaType.APPLICATION_JSON)
                .content(objectMapper.writeValueAsString(product)))
                .andExpect(status().isCreated())
                .andExpect(jsonPath("$.id").exists());
    }

    @Test
    @DisplayName("Should return 404 for non-existent product")
    void shouldReturn404ForNonExistentProduct() throws Exception {
        mockMvc.perform(get("/products/99999"))
                .andExpect(status().isNotFound());
    }
}