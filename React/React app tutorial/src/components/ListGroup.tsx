//fragment is better than div
//can import fragment from react or also just use empty <>
import { MouseEvent } from "react";

function ListGroup() {
  let items = ["New York", "London", "Tokyo", "San Francisco"];

  //event handling logic
  const handleClick = (event: MouseEvent) => console.log(event);
  //type annotation -> we can specify the parameters and variables

  return (
    <>
      <h1>List</h1>
      {items.length === 0 && <p>No items Found</p>}
      <ul className="list-group">
        {items.map((items, index) => (
          <li className="list-group-item" key={items} onClick={handleClick}>
            {items}
          </li>
        ))}
      </ul>
    </>
  );
}

export default ListGroup;

//ctrl D after you select one item to select multiple of that element
//in react component cannot return more than one element

//using items.map -> jsx way of using a for loop but react will throw us an error
//as in the return statement can only use html or react components so we wrap them in {}

//react will throw an error on the website about each child requiring a key
//this is because later on react needs to know which specific part of the website
//needs to be updated

//true and "expression" = expression
//false and "expression" = false
