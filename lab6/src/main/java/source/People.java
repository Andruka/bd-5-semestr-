package source;
import javax.persistence.*;

import java.util.ArrayList;
import java.util.List;

@Entity
@Table(name = "peoples")
public class People {
	@Id
	@GeneratedValue(strategy=GenerationType.IDENTITY)
	@Column(name = "id" , insertable = false, updatable = false)
	private Long id;

	@Column(name="firstname", nullable = false, length = 64)
	private String firstName;
	
	@Column(name = "lastname", nullable = false, length = 64)
	private String lastName;
    @OneToMany(mappedBy="base", targetEntity=Aircraft.class, fetch=FetchType.LAZY)
    private List<Aircraft> aircrafts = new ArrayList<>();

    public List<Aircraft> getAircrafts() {
        return aircrafts;
    }

    public void setAircrafts(List<Aircraft> aircrafts) {
        this.aircrafts = aircrafts;
    }
    
    @OneToMany(mappedBy="base", targetEntity = Car.class, fetch=FetchType.LAZY)
    private	List<Car> cars = new ArrayList<>();

    public List<Car> getCars() {
        return cars;
    }

    public void setCars(List<Car> cars) {
        this.cars = cars;
    }
    
    @OneToMany(mappedBy="base", targetEntity = Helicopter.class, fetch=FetchType.LAZY)
    private	List<Helicopter> helicopters= new ArrayList<>();
    public List<Helicopter> getHelicopters() {
        return helicopters;
    }

    public void setHelicopters(List<Helicopter> helicopters) {
        this.helicopters = helicopters;
    }

    @OneToMany(mappedBy="base", targetEntity= Tank.class, fetch=FetchType.LAZY)
    private	List<Tank> tanks = new ArrayList<>();
    public List<Tank> getTanks() {
        return tanks;
    }

    public void setTanks(List<Tank> tanks) {
        this.tanks = tanks;
    }
    
    @OneToMany(mappedBy="base", targetEntity=Spaceship.class, fetch=FetchType.LAZY)
    private List<Spaceship> spaceships = new ArrayList<>();

    public List<Spaceship> getSpaceships() {
        return spaceships;
    }

    public void setSpaceships(List<Spaceship> spaceships) {
        this.spaceships = spaceships;
    }
    
    
    public Long getId() {
        return id;
    }
	public String getFirstName() {
		return this.firstName;
	}
	
	public void setFirstName(String firstName) {
		this.firstName = firstName;
	}
	
	public String getLastName() {
		return lastName;
	}

	public void setLastName(String lastName) {
		this.lastName = lastName;
	}

	@Override
	public String toString() {
		return String.format("people(%d), %s %s ", getId(), lastName, firstName);
	}
}
