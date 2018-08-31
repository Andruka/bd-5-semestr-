package source;

import org.springframework.beans.factory.annotation.Autowired;
import javax.persistence.EntityManager;
import javax.transaction.Transactional;
import java.util.List;
import java.util.Scanner;

public class BaseService implements BaseProvider{
    @Autowired
    private BaseRepository baseRepository;

    @Autowired
    private EntityManager em;

    @Override
    @Transactional
    public void addOne() {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the adress : ");
        String adress= in.nextLine();
        System.out.print("Enter the name");
        String name = in.nextLine();
        Base newbase = new Base();
        newbase.setAdress(adress);
        newbase.setName(name);
        em.persist(newbase);
    }

    @Override
    @Transactional
    public Base getOne() {
        Scanner in = new Scanner(System.in);
        this.getAll().forEach(r -> {
            System.out.println(r);
        });
        System.out.print("Enter the id of room to choose : ");
        long id = in.nextLong();

        return baseRepository.findOne(id);
    }

    @Override
    @Transactional
    public List<Base> getAll() {
        return baseRepository.findAll();
    }

    @Override
    @Transactional
    public void deleteOne() {
        Base base = this.getOne();
        baseRepository.delete(base.getId());
    }

    @Override
    @Transactional
    public void updateOne() {
        Scanner in = new Scanner(System.in);
        Base updated = this.getOne();
        System.out.print("Enter new adress (enter '!' to skip): ");
        String adress = in.nextLine();
        if (!adress.equals("!")) {
            updated.setAdress(adress);
        }
        System.out.print("Enter new name (enter '!' to skip): ");
        String name = in.nextLine();
        if (!name.equals("!")) {
            updated.setName(name);
        }
        em.merge(updated);
    }

    @Override
    @Transactional
    public void showAllBase() {
        Base base = this.getOne();
        base.getAircrafts().forEach(System.out::println);
        base.getCars().forEach(System.out::println);
        base.getHelicopters().forEach(System.out::println);
        base.getTanks().forEach(System.out::println);
    }

    @Override
    @Transactional
    public void showOneBase() {
        Scanner in = new Scanner(System.in);
        Base base = this.getOne();
        System.out.println("1) Show all aircrafts");
        System.out.println("2) Show all cars");
        System.out.println("3) Show all helicopters");
        System.out.println("4) Show all tanks");
        int sub = in.nextInt();
        if (sub < 0 || sub > 4) {
            System.out.println("Incorrect value");
            return;
        }
        switch (sub) {
            case 1:
            	base.getAircrafts().forEach(System.out::println);
                break;
            case 2:
            	base.getCars().forEach(System.out::println);
                break;
            case 3:
            	base.getHelicopters().forEach(System.out::println);
                break;
            case 4:
            	base.getTanks().forEach(System.out::println);
                break;
        }
    }

    @Override
    @Transactional
    public void search() {
        Scanner in = new Scanner(System.in);
        System.out.println("1) Find all transport for base");
        System.out.println("2) Find one transport for base");
        int subChoseFindRoom = in.nextInt();
        if (subChoseFindRoom < 1 || subChoseFindRoom > 2) {
            System.out.println("Incorrect value");
            return;
        }
        switch (subChoseFindRoom) {
            case 1:
                this.showAllBase();
                break;
            case 2:
                this.showOneBase();
                break;
        }
    }
}
