package me.michal.restapi.controller;

import lombok.RequiredArgsConstructor;
import me.michal.restapi.model.Product;
import me.michal.restapi.repository.ProductRepository;

import org.springframework.data.domain.*;
import org.springframework.http.*;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/products")
@RequiredArgsConstructor
public class ProductController {

    private final ProductRepository productRepository;

    @GetMapping
    public Page<Product> getAll(@RequestParam(defaultValue = "0") int page,
                                @RequestParam(defaultValue = "10") int size,
                                @RequestParam(defaultValue = "id") String sort) {
        return productRepository.findAll(PageRequest.of(page, size, Sort.by(sort)));
    }

    @GetMapping("/{id}")
    public ResponseEntity<Product> get(@PathVariable Long id) {
        return productRepository.findById(id)
                .map(ResponseEntity::ok)
                .orElse(ResponseEntity.notFound().build());
    }

    @PostMapping
    public ResponseEntity<Product> create(@RequestBody Product product) {
        return ResponseEntity.status(HttpStatus.CREATED).body(productRepository.save(product));
    }

    @PutMapping("/{id}")
    public ResponseEntity<Product> update(@PathVariable Long id, @RequestBody Product product) {
        return productRepository.findById(id)
                .map(p -> {
                    p.setName(product.getName());
                    p.setDescription(product.getDescription());
                    return ResponseEntity.ok(productRepository.save(p));
                })
                .orElse(ResponseEntity.notFound().build());
    }

    @DeleteMapping("/{id}")
    public ResponseEntity<Void> delete(@PathVariable Long id) {
        if (!productRepository.existsById(id)) return ResponseEntity.notFound().build();
        productRepository.deleteById(id);
        return ResponseEntity.noContent().build();
    }
}