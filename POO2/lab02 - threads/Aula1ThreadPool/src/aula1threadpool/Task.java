/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula1threadpool;

import java.util.concurrent.TimeUnit;
 
public class Task implements Runnable {
    private String name;
 
    public Task(String name) {
        this.name = name;
    }
 
    public String getName() {
        return name;
    }
 
    public void run() {
        try {
            Long duration = (long) (Math.random() * 15);
            System.out.println("Executando : " + name);
            TimeUnit.SECONDS.sleep(duration);
            System.out.println("Terminou : " + name);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
