package me.michal.restapi.controller;

import lombok.RequiredArgsConstructor;
import me.michal.restapi.model.Review;
import me.michal.restapi.repository.ProductRepository;
import me.michal.restapi.repository.ReviewRepository;
import me.michal.restapi.repository.UserRepository;

import org.springframework.data.domain.*;
import org.springframework.http.*;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/reviews")
@RequiredArgsConstructor
public class ReviewController {

    private final ReviewRepository reviewRepository;
    private final UserRepository userRepository;
    private final ProductRepository productRepository;

    @GetMapping
    public Page<Review> getAll(@RequestParam(defaultValue = "0") int page,
                               @RequestParam(defaultValue = "10") int size) {
        return reviewRepository.findAll(PageRequest.of(page, size));
    }

    @PostMapping
    public ResponseEntity<?> create(@RequestBody Review review) {
        // Check that user and product exist and assign
        var user = userRepository.findById(review.getUser().getId());
        var product = productRepository.findById(review.getProduct().getId());
        if (user.isEmpty() || product.isEmpty()) return ResponseEntity.badRequest().body("Invalid user or product");
        review.setUser(user.get());
        review.setProduct(product.get());
        return ResponseEntity.status(HttpStatus.CREATED).body(reviewRepository.save(review));
    }

    @DeleteMapping("/{id}")
    public ResponseEntity<Void> delete(@PathVariable Long id) {
        if (!reviewRepository.existsById(id)) return ResponseEntity.notFound().build();
        reviewRepository.deleteById(id);
        return ResponseEntity.noContent().build();
    }
}