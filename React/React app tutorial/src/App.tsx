import Button from "./components/Button";
import Alert from "./components/Alert";
import { useState } from "react";


function App() {
  const[alertVisible, setAlertVisibility] = useState(false);

  return (
    <div>
      {alertVisible && <Alert onClose={()=>setAlertVisibility(false)}>What?</Alert>}
      <Button onSelectedItem = {()=> setAlertVisibility(true)}>Button</Button>
    </div>
  );
}

//export app so it can be used somewhere else
export default App;
