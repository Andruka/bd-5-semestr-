package source;

import javax.persistence.Column;
import javax.persistence.Table;
import javax.persistence.Entity;

@Entity
@Table(name = "spaceship")
public class Spaceship extends AirTransport {

	@Column(name = "payload")
    protected Integer payload;

    public Integer getPayload() {
        return payload;
    }

    public void setPayload(Integer payload) {
        this.payload = payload;
    }

    @Override
    public String toString() {
        return  String.format("%s , payload: %d " , super.toString(),  payload);
    }
}
