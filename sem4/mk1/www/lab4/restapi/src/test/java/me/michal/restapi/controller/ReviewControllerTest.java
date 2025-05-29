package me.michal.restapi.controller;

import me.michal.restapi.model.Product;
import me.michal.restapi.model.Review;
import me.michal.restapi.model.User;
import me.michal.restapi.repository.ProductRepository;
import me.michal.restapi.repository.ReviewRepository;
import me.michal.restapi.repository.UserRepository;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.AutoConfigureMockMvc;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.http.MediaType;
import org.springframework.security.test.context.support.WithMockUser;
import org.springframework.test.web.servlet.MockMvc;
import com.fasterxml.jackson.databind.ObjectMapper;

import static org.hamcrest.Matchers.*;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.*;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.*;

@SpringBootTest
@AutoConfigureMockMvc
class ReviewControllerTest {

    @Autowired
    private MockMvc mockMvc;
    @Autowired
    private ReviewRepository reviewRepository;
    @Autowired
    private ProductRepository productRepository;
    @Autowired
    private UserRepository userRepository;
    @Autowired
    private ObjectMapper objectMapper;

    private User user;
    private Product product;
    private Review review;

    @BeforeEach
    void setup() {
        reviewRepository.deleteAll();
        userRepository.deleteAll();
        productRepository.deleteAll();

        user = userRepository.save(User.builder().username("reviewer").password("pass").role("USER").build());
        product = productRepository.save(Product.builder().name("Prod").description("desc").build());
        review = reviewRepository.save(Review.builder().user(user).product(product).content("Good!").build());
    }

    @Test
    @DisplayName("Should return paginated reviews")
    @WithMockUser(roles = "ADMIN")
    void shouldReturnPaginatedReviews() throws Exception {
        mockMvc.perform(get("/reviews?page=0&size=2"))
                .andExpect(status().isOk())
                .andExpect(jsonPath("$.content").exists());
    }

    @Test
    @DisplayName("Should return 400 when user or product not exists")
    @WithMockUser(roles = "ADMIN")
    void shouldReturn400ForBadUserOrProduct() throws Exception {
        User fakeUser = User.builder().id(9999L).build();
        Product fakeProduct = Product.builder().id(9999L).build();
        Review toCreate = Review.builder()
                .content("Invalid test")
                .user(fakeUser)
                .product(fakeProduct)
                .build();

        mockMvc.perform(post("/reviews")
                .contentType(MediaType.APPLICATION_JSON)
                .content(objectMapper.writeValueAsString(toCreate)))
                .andExpect(status().isBadRequest())
                .andExpect(content().string(containsString("Invalid user or product")));
    }

    @Test
    @DisplayName("Should delete review")
    @WithMockUser(roles = "ADMIN")
    void shouldDeleteReview() throws Exception {
        mockMvc.perform(delete("/reviews/" + review.getId()))
                .andExpect(status().isNoContent());
    }

    @Test
    @DisplayName("Should return 404 for deleting non-existent review")
    @WithMockUser(roles = "ADMIN")
    void shouldReturn404WhenDeleteNonExistentReview() throws Exception {
        mockMvc.perform(delete("/reviews/99999"))
                .andExpect(status().isNotFound());
    }

    @Test
    @DisplayName("Should return 401 when unauthenticated")
    void shouldReturn401WhenUnauthenticated() throws Exception {
        mockMvc.perform(get("/reviews"))
        .andExpect(status().isForbidden());
    }

    @Test
    @DisplayName("Should return 403 for creating review as USER")
    @WithMockUser(roles = "USER")
    void shouldReturn403ForCreateAsUser() throws Exception {
        Review toCreate = Review.builder()
                .content("Forbidden")
                .user(user)
                .product(product)
                .build();

        mockMvc.perform(post("/reviews")
                .contentType(MediaType.APPLICATION_JSON)
                .content(objectMapper.writeValueAsString(toCreate)))
                .andExpect(status().isForbidden());
    }
}