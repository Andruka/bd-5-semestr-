package source;

import javax.transaction.Transactional;


import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.Bean;

import java.util.Scanner;


@SpringBootApplication
public class Main{
	
	private static final Logger LOGGER = LoggerFactory.getLogger(Main.class);
	
	@Bean
	public PeopleProvider PeopleProvider() {
		return new PeopleService();
	}
	
	@Bean
	public AircraftProvider AircraftProvider() {
		return new AircraftService();
	}

	@Bean
	public BaseProvider BaseProvider() {
		return new BaseService();
	}

	@Bean
	public CarProvider CarProvider() {
		return new CarService();
	}

	@Bean
	public HelicopterProvider HelicopterProvider() {
		return new HelicopterService();
	}

	@Bean
	public TankProvider TankProvider() {
		return new TankService();
	}
	
	@Bean
	public SpaceshipProvider SpaceshipProvider() {
		return new SpaceshipService();
	}


	public static void main(String[] args) {
		SpringApplication.run(Main.class, args);
	}
	
	
	@Bean
	@Transactional
	public CommandLineRunner run(final PeopleProvider peopleService,
								 final AircraftProvider aircraftService,
								 final BaseProvider baseService,
								 final CarProvider carService,
								 final HelicopterProvider helicopterService,
								 final TankProvider tankService,
								 final TankProvider spaceshipService) {
		return new CommandLineRunner() {
			
			@Override
			public void run(String... arg0) throws Exception {
				LOGGER.info("*** started ***");
				Scanner menu = new Scanner(System.in);
				while (true) {
					System.out.println("1) Show...");
					System.out.println("2) Add...");
					System.out.println("3) Update...");
					System.out.println("4) Delete...");
					System.out.println("5) Find...");
					System.out.println("0) Exit");
					int chosen = menu.nextInt();
					if (chosen < 0 || chosen > 5) {
						System.out.println("Incorrect value");
						continue;
					}
					switch (chosen) {
						case 1:
							System.out.println("1) Show all people");
							System.out.println("2) Show all aircrafts");
							System.out.println("3) Show all bases");
							System.out.println("4) Show all cars");
							System.out.println("5) Show all helicopters");
							System.out.println("6) Show all tanks");
							System.out.println("7) Show all spaceships");
							int subChoseShow = menu.nextInt();
							if (subChoseShow < 1 || subChoseShow > 7) {
								System.out.println("Incorrect value");
								continue;
							}
							switch (subChoseShow) {
								case 1:
									peopleService.getAll().forEach(System.out::println);
									break;
								case 2:
									aircraftService.getAll().forEach(System.out::println);
									break;
								case 3:
									baseService.getAll().forEach(System.out::println);
									break;
								case 4:
									carService.
									getAll().forEach(System.out::println);
									break;
								case 5:
									helicopterService.getAll().forEach(System.out::println);
									break;
								case 6:
									tankService.getAll().forEach(System.out::println);
									break;
								case 7:
									spaceshipService.getAll().forEach(System.out::println);
									break;		
							}
							break;
						case 2:
							System.out.println("1) Add people");
							System.out.println("2) Add aircraft");
							System.out.println("3) Add base");
							System.out.println("4) Add car");
							System.out.println("5) Add helicopter");
							System.out.println("6) Add tank");
							System.out.println("7) Add spaceship");
							int subChoseAdd = menu.nextInt();
							if (subChoseAdd < 1 || subChoseAdd > 7) {
								System.out.println("Incorrect value");
								continue;
							}
							switch (subChoseAdd) {
								case 1:
									peopleService.addOne();
									break;
								case 2:
									aircraftService.addOne();
									break;
								case 3:
									baseService.addOne();
									break;
								case 4:
									carService.addOne();
									break;
								case 5:
									helicopterService.addOne();
									break;
								case 6:
									tankService.addOne();
									break;
								case 7:
									spaceshipService.addOne();
									break;
							}
							break;
						case 3:
							System.out.println("1) Update people");
							System.out.println("2) Update aircraft");
							System.out.println("3) Update base");
							System.out.println("4) Update car");
							System.out.println("5) Update helicopter");
							System.out.println("6) Update tank");
							System.out.println("7) Update spaceship");
							int subChoseUpdate = menu.nextInt();
							if (subChoseUpdate < 1 || subChoseUpdate > 7) {
								System.out.println("Incorrect value");
								continue;
							}
							switch (subChoseUpdate) {
								case 1:
									peopleService.updateOne();
									break;
								case 2:
									aircraftService.updateOne();
									break;
								case 3:
									baseService.updateOne();
									break;
								case 4:
									carService.updateOne();
									break;
								case 5:
									helicopterService.updateOne();
									break;
								case 6:
									tankService.updateOne();
									break;
								case 7:
									spaceshipService.updateOne();
									break;
							}
							break;
						case 4:
							System.out.println("1) Delete people");
							System.out.println("2) Delete aircraft");
							System.out.println("3) Delete base");
							System.out.println("4) Delete car");
							System.out.println("5) Delete helicopter");
							System.out.println("6) Delete tank");
							System.out.println("7) Delete spaceship");
							int subChoseDelete = menu.nextInt();
							if (subChoseDelete < 1 || subChoseDelete > 7) {
								System.out.println("Incorrect value");
								continue;
							}
							switch (subChoseDelete) {
								case 1:
									peopleService.deleteOne();
									break;
								case 2:
									aircraftService.deleteOne();
									break;
								case 3:
									baseService.deleteOne();
									break;
								case 4:
									carService.deleteOne();
									break;
								case 5:
									helicopterService.deleteOne();
									break;
								case 6:
									tankService.deleteOne();
									break;
								case 7:
									spaceshipService.deleteOne();
									break;
							}
							break;
						case 5:
							System.out.println("1) Find transport by base");
							System.out.println("2) Find transport by people");
							int subChoseFind = menu.nextInt();
							if (subChoseFind < 1 || subChoseFind > 2) {
								System.out.println("Incorrect value");
								continue;
							}
							switch (subChoseFind) {
								case 1:
									baseService.search();
									menu.nextLine();
									break;
								case 2:
									peopleService.search();
									menu.nextLine();
									break;
							}
							break;
						case 0:
							return;
					}
				}
			}
		};
	}
}
