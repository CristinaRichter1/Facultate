package examen;

import java.io.Serializable;

public class Car implements Vehicle,Serializable,Cloneable {

	private float weight;
	private double price;
	private String model;
	
	public Car() {
		super();
	}

	public float getWeight() {
		return weight;
	}

	public void setWeight(float weight) throws Exception {
		if(weight<0) {
			throw new Exception();
		} else {
		this.weight = weight;
		}
	}

	public double getPrice() {
		return price;
	}

	public void setPrice(double price) throws Exception {
		if(price<0) {
			throw new Exception();
		} else {
		this.price = price;
		}
	}

	public String getModel() {
		return model;
	}

	public void setModel(String model) throws Exception {
		if(model==null && model.length()<1) {
			throw new Exception();
		} else {
		this.model = model;
		}
	}

	

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((model == null) ? 0 : model.hashCode());
		long temp;
		temp = Double.doubleToLongBits(price);
		result = prime * result + (int) (temp ^ (temp >>> 32));
		result = prime * result + Float.floatToIntBits(weight);
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (!(obj instanceof Car))
			return false;
		Car other = (Car) obj;
		if (model == null) {
			if (other.model != null)
				return false;
		} else if (!model.equals(other.model))
			return false;
		if (Double.doubleToLongBits(price) != Double.doubleToLongBits(other.price))
			return false;
		if (Float.floatToIntBits(weight) != Float.floatToIntBits(other.weight))
			return false;
		return true;
	}
	
	

	@Override
	protected Object clone() throws CloneNotSupportedException {
		
		return super.clone();
	}

	@Override
	public String getDetails() {		
		return null;
	}

}
