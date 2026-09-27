import Button from "./components/Button";
function App() {
  return (
    <div>
      <Button onSelectedItem = {()=> console.log("Clicked")}>Button</Button>
    </div>
  );
}

//export app so it can be used somewhere else
export default App;
