import java.util.ArrayList;
import java.util.Arrays;
public class Main {
    public static void main(String[] args) {
        ArrayList<Atleta> lista1 = new ArrayList<>();
        Atleta[] lista2 = new Atleta[3];
        Atleta atleta1 = new Futebolista("Joao", 18, 60, 1.75f);
        Atleta atleta2 = new Tenista("Arthur", 25, 70, 1.50f);
        Atleta atleta3 = new Corredor("Victor", 20, 75, 1.90f);
        lista1.add(atleta1);
        lista1.add(atleta2);
        lista1.add(atleta3);
        lista2[0] = atleta1;
        lista2[1] = atleta2;
        lista2[2] = atleta3;
        lista1.sort(null);
        Arrays.sort(lista2);
        for(int i=0; i<3; i++){
            System.out.println(lista2[i].toString());
            lista2[i].aquecer(10);
            lista2[i].jogar();
        }
        for (Atleta atleta : lista2) {
            System.out.println(atleta.toString());
            atleta.aquecer(10);
            atleta.jogar();
        }
        Atleta.calcularProximaOlimpiada();
    }
}