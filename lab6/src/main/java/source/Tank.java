package source;

import javax.persistence.Column;
import javax.persistence.Table;
import javax.persistence.Entity;

@Entity
@Table(name = "tank")
public class Tank extends LandTransport {

	@Column(name = "shot")
    protected Integer shot;

    public Integer getShot() {
        return shot;
    }

    public void setShot(Integer shot) {
        this.shot = shot;
    }

    @Override
    public String toString() {
        return  String.format("%s , shot: %d " , super.toString(),  shot);
    }
}
