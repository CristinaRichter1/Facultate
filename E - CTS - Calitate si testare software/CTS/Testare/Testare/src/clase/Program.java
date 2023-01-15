package clase;

import java.util.List;

public class Program {

	public static void main(String[] args) {
		Utile ut=new Utile();
		List<Integer> lista=ut.n_numere_pare(10);
		for(int a:lista)
		{
			System.out.println(a);
		}

	}

}
