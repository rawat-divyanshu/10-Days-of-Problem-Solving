import java.util.Scanner;

interface Shape {
    public double perimeterCalculation();
    public double areaCalculation();
}

class Circle implements Shape {
  double radius;

  Circle(double radius) {
    this.radius = radius;
  }

  public double perimeterCalculation() {
    return 2*(Math.PI)*(this.radius);
  }

  public double areaCalculation() {
    return (Math.PI)*(Math.pow(this.radius, 2));
  }
}

class Ellipse implements Shape {
  double majorRadius;
  double minorRadius;

  Ellipse(double majorRadius, double minorRadius) {
    this.majorRadius = majorRadius;
    this.minorRadius = minorRadius;
  }

  public double perimeterCalculation() {
    double cal = (Math.pow(this.majorRadius, 2) + Math.pow(this.minorRadius, 2))/2;
    return 2*(Math.PI)*(Math.sqrt(cal));
  }

  public double areaCalculation() {
    return (Math.PI)*(this.majorRadius)*(this.minorRadius);
  }
}

class Main {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);

    String inp = scan.nextLine();
    String[] radii = inp.split(",", 2);
    if(Double.parseDouble(radii[1]) == 0) {
      double radius = Double.parseDouble(radii[0]);
      Circle c1 = new Circle(radius);
      System.out.println("Perimeter of given Circle is " + c1.perimeterCalculation());
      System.out.println("Area of given Circle is " + c1.areaCalculation());
    } else {
      double majorRadius = Double.parseDouble(radii[0]);
      double minorRadius = Double.parseDouble(radii[1]);
      Ellipse e1 = new Ellipse(majorRadius, minorRadius);
      System.out.println("Perimeter of given Ellipse is " + e1.perimeterCalculation());
      System.out.println("Area of given Ellipse is " + e1.areaCalculation());
    }
  }
}