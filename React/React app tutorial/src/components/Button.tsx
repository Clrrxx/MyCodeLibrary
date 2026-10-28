interface props {
  children: string;
  color?: string  //? siginfies to tsx that assignment is optional
  onSelectedItem: () => void;
  
}

const Button = ({children, color = 'primary', onSelectedItem} : props) => {
  return <button className={"btn btn-"+color} onClick={onSelectedItem}>{children}</button>;
};

export default Button;
