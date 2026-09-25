//fragment is better than div

function ListGroup() {
  return (
    <>   
        <h1>List</h1>
        <ul className="list-group">
          <li className="list-group-item">An item</li>
          <li className="list-group-item">A second item</li>
          <li className="list-group-item">A third item</li>
          <li className="list-group-item">A fourth item</li>
          <li className="list-group-item">And a fifth one</li>
        </ul>
    </>
  );
}
//ctrl D after you select one item to select multiple of that element
//in react component cannot return more than one element

export default ListGroup;
