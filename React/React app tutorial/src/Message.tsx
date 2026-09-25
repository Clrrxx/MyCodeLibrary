//Creating a message component using Typescript

//pascal casing when creating function components
function Message(){
//describing what should be inside a H1 element with Hello World
    //code gets converted to Javascript
    //using JSX => we can do dynamic content
    const name = 'Josh';
    if (name) 
        return <h1>Hello {name}</h1>;
    return <h1>Hello World</h1>;
}

export default Message






