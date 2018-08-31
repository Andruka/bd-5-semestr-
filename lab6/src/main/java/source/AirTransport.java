package source;

import javax.persistence.Column;
import javax.persistence.MappedSuperclass;
import javax.persistence.Table;

@MappedSuperclass
@Table(name = "air_transport")
public class AirTransport extends Transport {
	//	Ceiling (aeronautics) практический потолок -  это максимальная высота реального применения самолёта, вертолёта
	
	// срок эксплуатации
    @Column(name = "lifetime")
    protected Integer lifetime;

    public Integer getLifetime() {
        return lifetime;
    }

    public void setLifetime(Integer lifetime) {
        this.lifetime = lifetime;
    }

    @Override
    public String toString() {
        return  String.format("%s , lifetime: %d " , super.toString(),  lifetime);
    }
}