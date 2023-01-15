package examen;

public class ElectricCar extends Car {
	
	private int batteryLife;

	public int getBatteryLife() {
		return batteryLife;
	}

	public void setBatteryLife(int batteryLife) throws Exception {
		if(batteryLife<0) {
			throw new Exception();
		} else {
		this.batteryLife = batteryLife;
		}
	}

	@Override
	public String getDetails() {
		
		return String.valueOf(batteryLife);
	}
}
