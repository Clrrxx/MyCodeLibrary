//fragment is better than div
//can import fragment from react or also just use empty <>

function ListGroup() {
  const items = ["New York", "London", "Tokyo", "San Francisco"];

  return (
    <>
      <h1>List</h1>
      <ul className="list-group">
        {items.map((items) => (
          <li key={items}>{items}</li>
        ))}
      </ul>
    </>
  );
}
//ctrl D after you select one item to select multiple of that element
//in react component cannot return more than one element

//using items.map -> jsx way of using a for loop but react will throw us an error
//so we wrap them in {} 

export default ListGroup;
