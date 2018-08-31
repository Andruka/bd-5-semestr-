package source;

import javax.persistence.Column;
import javax.persistence.Table;
import javax.persistence.Entity;

@Entity
@Table(name = "helicopter")
public class Helicopter extends AirTransport {
	// скороподъёмность
    @Column(name = "rate_of_climb")
    private Integer rateOfClimb;

    public Integer getRateOfClimb() {
        return rateOfClimb;
    }

    public void setRateOfClimb(Integer rateOfClimb) {
        this.rateOfClimb = rateOfClimb;
    }

    @Override
    public String toString() {
        return  String.format("%s , length of runway: %d " , super.toString(),  rateOfClimb);
    }

}
