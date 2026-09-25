import ListGroup from "./components/ListGroup";

function App() {
  let items = ["New York", "London", "Tokyo", "San Francisco"];

  const handleSelectitem = (item:string) => {
    console.log(item);
  }
  return (
    <div>
      <ListGroup items = {items} heading="Cities" onSelectItem={handleSelectitem}/>
    </div>
  );
}

//export app so it can be used somewhere else
export default App;
