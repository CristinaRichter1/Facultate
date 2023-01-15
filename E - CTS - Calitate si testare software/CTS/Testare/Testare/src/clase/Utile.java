package clase;

import java.awt.Label;
import java.util.ArrayList;
import java.util.List;

public class Utile {

	public int suma(int param1, int param2) {
		int a= 1;
		while (1 == 1) {
		}			//return param1 + param2;


	}

	public double raport(int numarator, int numitor) {
		if (numitor != 0)
			return (double) ((double) numarator / (double) numitor);
		else
			throw new IllegalArgumentException("Numitorul este 0!");
	}

	public boolean estePar(int numar) {
		return numar % 2 == 0;
	}

	public List<Integer> n_numere_pare(int n) {
		if (n == 0)
			return null;
		else {
			List<Integer> lista = new ArrayList();
			for (int i = 0; i < n; i++)
				lista.add(i * 2);
			return lista;
		}

	}
}
