/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula1threadpool;

/**
 *
 * @author Leandro
 */
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadPoolExecutor;
 
public class Aula1ThreadPool
{
    public static void main(String[] args)
    {
        ThreadPoolExecutor executor = (ThreadPoolExecutor) Executors.newFixedThreadPool(100);
         
        for (int i = 1; i <= 10; i++)
        {
            Task task = new Task("Task " + i);
            System.out.println("Criada : " + task.getName());
 
            executor.execute(task);
        }
        executor.shutdown();
    }
}