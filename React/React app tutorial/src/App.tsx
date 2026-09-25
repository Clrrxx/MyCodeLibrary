import ListGroup from "./components/ListGroup";

function App() {
  let items = ["New York", "London", "Tokyo", "San Francisco"];

  return (
    <div>
      <ListGroup items = {items} heading="Cities"/>
    </div>
  );
}

//export app so it can be used somewhere else
export default App;
