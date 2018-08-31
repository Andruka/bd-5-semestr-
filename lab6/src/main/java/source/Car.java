package source;

import javax.persistence.Column;
import javax.persistence.Table;
import javax.persistence.Entity;

@Entity
@Table(name = "car")
public class Car extends LandTransport {

    @Column(name = "acceleration_time")
    protected Double accelerationTime;

    public Double getAccelerationTime() {
        return accelerationTime;
    }

    public void setAccelerationTime(Double accelerationTime) {
        this.accelerationTime = accelerationTime;
    }

    @Override
    public String toString() {
        return  String.format("%s , acceleration time: %f " , super.toString(),  accelerationTime);
    }
}


