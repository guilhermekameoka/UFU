package com.example.demo;

import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

@RestController
public class AddressController {

    private final List<Address> addresses = new ArrayList<>(
            Arrays.asList(
                    new Address("38400100", "Floriano Peixoto", "Centro", "Uberlândia"),
                    new Address("38400200", "Tiradentes", "Fundinho", "Uberlândia"),
                    new Address("38400300", "Lions Clube", "Osvaldo Rezende", "Uberlândia")
            )
    );

    @GetMapping("/hello")
    public String helloworld(){
        return "Hello World!";
    }

    @GetMapping("/address")
    public List<Address> getAddresses(){
        return this.addresses;
    }

    @GetMapping("/address/{cep}")
    public ResponseEntity<Address> getAddress(@PathVariable String cep){
        for (Address address : this.addresses)
            if(address.getCep().equals(cep))
                return ResponseEntity.ok(address);
        return ResponseEntity.notFound().build();
    }

    @PostMapping("/address")
    public void addAddress(@RequestBody Address address){
        this.addresses.add(address);
    }

    @DeleteMapping("/address")
    public void remAddress(@RequestBody Address address){
        this.addresses.remove(address);
    }


}