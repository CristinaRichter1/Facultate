package examen;

import java.util.ArrayList;
import java.util.List;

public class VectThread implements Runnable {

	private List<Car> carsList=new ArrayList<>();
	private double avgWeight;
	
	public VectThread() {
		
		super();
		//this.carsList=Utils.readBinaryCars("fisier.bin");
	}

	public List<Car> getCarsList() {
		return carsList;
	}

	public void setCarsList(List<Car> carsList) {
		this.carsList = carsList;
	}

	public double getAvgWeight() {
		return avgWeight;
	}

	public void setAvgWeight(double avgWeight) {
		this.avgWeight = avgWeight;
	}


	@Override
	public void run() {
		float sumaGreutate=0;
		int nr=0;
		
		for (Car vehicle : carsList) {
			sumaGreutate=sumaGreutate+vehicle.getWeight();
			nr++;
		}
		
		avgWeight=sumaGreutate/nr;
		
	}

}
