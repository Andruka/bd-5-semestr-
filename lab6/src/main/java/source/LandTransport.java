package source;

import javax.persistence.Column;
import javax.persistence.MappedSuperclass;
import javax.persistence.Table;

@MappedSuperclass
@Table(name = "land_transport")
public class LandTransport extends Transport {

    @Column(name = "mileage")
    protected Integer mileage;

    public Integer getMileage() {
        return mileage;
    }

    public void setMileage(Integer mileage) {
        this.mileage = mileage;
    }

    @Override
    public String toString() {
        return  String.format("%s , mileage: %d " , super.toString(),  mileage);
    }

}