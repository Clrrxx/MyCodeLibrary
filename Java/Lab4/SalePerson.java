public class SalePerson implements Comparable<SalePerson>{
    private String firstname;
    private String lastname;
    private int totalsale;

    public SalePerson(String firstname, String lastname, int totalsale){
        this.firstname = firstname;
        this.lastname = lastname;
        this.totalsale = totalsale;
    }
    
    public String getfirstname(){return firstname;}
    public String getlastname() {return lastname;}
    public int gettotalsale() {return totalsale;}

    @Override
    public String toString(){
        return lastname + "," + firstname + ":" + totalsale;
    }

    public boolean equals(Object obj){
        //if the name provided is the same => return true
        if (this == obj){
            return true;
        }
        //if not return false after checking if it appears at all
        if (!(obj instanceof SalePerson)){
            return false;
        }
        
        SalePerson sales = (SalePerson) obj;

        return firstname.equals(sales.firstname) && lastname.equals(sales.lastname);
    }
    public int compareTo(SalePerson sale){
        //if sales does not match return the difference between them (-ve number)
        if (this.totalsale != sale.totalsale){
            return this.totalsale - sale.totalsale;
        }

        //if sales do match return the comparison value between the 2 lastnames to break tie
        return this.lastname.compareTo(sale.lastname);
    }
}
