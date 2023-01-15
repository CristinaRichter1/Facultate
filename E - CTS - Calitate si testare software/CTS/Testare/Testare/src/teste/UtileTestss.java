package teste;

import static org.junit.Assert.*;

import org.junit.Test;

import clase.Utile;

public class UtileTestss {

	@Test
	public void testSuma() {
		Utile utile = new Utile();
		int rezultat = utile.suma(1, 2);
		int rezultatAsteptat = 3;
		assertEquals("suma incorecta", rezultatAsteptat, rezultat);
	}
	
	@Test
	public void testRaport() {
		Utile utile = new Utile();
		double rezultat = utile.raport(6, 3);
		double rezultatAsteptat = 2;
		//assertEquals(message, expected, actual, delta);
		assertEquals("Raport incorect", rezultatAsteptat, rezultat, 0.1);
	}
	
	@Test(expected=IllegalArgumentException.class)
	public void testRaportInput() {
		Utile utile = new Utile();
		double actual_result = 0;
		actual_result = utile.raport (5,0);
		fail("Eroare");
	}
	
	@Test
	public void testPerformanta() {
		Utile utile = new Utile();
		int rezultat = utile.suma(1, 2);
	}

}