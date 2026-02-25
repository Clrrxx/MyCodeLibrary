public class VendingMachineApp {
    public static void main(String[] args) {
        VendingMachine vm = new VendingMachine();
        double drcost = 0, amountinse = 0.0;
        drcost = vm.selectDrink();
        amountinse = vm.insertCoins(drcost);
        vm.checkChange(amountinse, drcost);
        vm.printReceipt();
    }
}
