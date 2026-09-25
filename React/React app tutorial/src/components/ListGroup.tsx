//fragment is better than div
//can import fragment from react or also just use empty <>

import { useState } from "react";

// {items: [], heading: string} -> use interface like class
interface Props{
  items: string[];
  heading: string;
}

function ListGroup({items, heading}: Props) {
  
  
  //Hook => tell react that the variable will change states
  const [selectedIndex, setSelectedIndex] = useState(-1);
    
  //arr[0]  //var (selected index)
  //arr[1]  //updater function
  

  return (
    <>
      <h1>{heading}</h1>
      {items.length === 0 && <p>No items Found</p>}
      <ul className="list-group">
        {items.map((items, index) => (
          <li
          //for item in list group, we are going to highlight the element that is clicked
            className={
              selectedIndex === index
                ? "list-group-item active"
                : "list-group-item"
            }
            key={items}
            onClick={()=> {setSelectedIndex(index);}}
          >
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
