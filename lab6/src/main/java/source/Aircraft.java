package source;

import javax.persistence.Column;
import javax.persistence.Table;
import javax.persistence.Entity;

@Entity
@Table(name = "aircraft")
public class Aircraft extends AirTransport {
	// дальность перелёта
    @Column(name = "range")
    private Integer range;

    public Integer getRange() {
        return range;
    }

    public void setRange(Integer range) {
        this.range = range;
    }

    @Override
    public String toString() {
        return  String.format("%s , range: %d " , super.toString(),  range);
    }
}