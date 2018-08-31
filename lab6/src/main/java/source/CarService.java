package source;

import java.util.List;
import java.util.Scanner;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.transaction.Transactional;
import org.springframework.beans.factory.annotation.Autowired;

public class CarService implements CarProvider{

	@Autowired
	private CarRepository carRepository;

	@Autowired
	private PeopleRepository peopleRepository;

	@Autowired
	private BaseRepository baseRepository;

	@PersistenceContext
	private EntityManager em;
	

	@Override
	public List<Car> getAll() {
		return carRepository.findAll();
	}

	@Override
	public Car getOne() {
		Scanner in = new Scanner(System.in);
		this.getAll().forEach(System.out::println);
		System.out.print("Enter id of car to choose : ");
		long id = in.nextLong();
		 
		return carRepository.findOne(id);
	}

	@Override
	@Transactional
	public void addOne() {
		System.out.println("*** add aircraft  ***");
		Car car = new Car();

		Scanner in = new Scanner(System.in);
		System.out.println("Choosing base : ");
		baseRepository.findAll().forEach(System.out::println);
		System.out.println("Choose id of base : ");
		long baseId = in.nextLong();
		in.nextLine();
		Base base = baseRepository.findOne(baseId);
		car.setBase(base);
		
		System.out.println("Choosing people : ");
		peopleRepository.findAll().forEach(System.out::println);
		System.out.println("Choose id of people: ");
		long peopleId = in.nextLong();
		in.nextLine();
		People people = peopleRepository.findOne(peopleId);
		car.setPeople(people);

		System.out.print("Enter the mileage : ");
		Integer mileage = in.nextInt();
		car.setMileage(mileage);

		System.out.print("Enter the range ");
		Double accelerationTime = in.nextDouble();
		car.setAccelerationTime(accelerationTime);
		
		em.persist(car);
		
	}

	@Override
	@Transactional
	public void deleteOne() {
		System.out.println("*** delete chair ***");
		Car deleted = this.getOne();
		carRepository.delete(deleted.getId());
	}

	@Override
	@Transactional
	public void updateOne() {
		Scanner in = new Scanner(System.in);
		System.out.println("*** update chair ***");
		Car updated = this.getOne();
		peopleRepository.findAll().forEach(System.out::println);
		System.out.print("Enter new  people (to skip enter '!'): ");
		String peopleId = in.nextLine();
		if (!peopleId.equals("!")) {
			long id = Long.parseLong(peopleId);
			updated.setPeople(peopleRepository.findOne(id));
		}
		baseRepository.findAll().forEach(System.out::println);
		System.out.print("Enter new  base (to skip enter '!'): ");
		String baseId = in.nextLine();
		if (!baseId.equals("!")) {
			long id = Long.parseLong(baseId);
			updated.setBase(baseRepository.findOne(id));
		}

		
		System.out.print("Enter new mileage (to skip enter '-1'): ");
		Integer mileage = in.nextInt();
		if (mileage != -1) {
				updated.setMileage(mileage);
		}
		System.out.print("Enter new range (to skip enter '0.0'): ");
		Double accelerationTime = in.nextDouble();
		if (accelerationTime != -1) {
			updated.setAccelerationTime(accelerationTime);
		}
		
		em.merge(updated);
		 
	}

	
}
