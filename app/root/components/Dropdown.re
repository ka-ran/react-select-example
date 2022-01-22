[@react.component]
let make =
    (
      ~target: React.element,
      ~isOpen: bool,
      ~children: React.element,
      ~onClose: unit => unit,
    ) => {
  <div className="c-dropdown">
    target
    {isOpen
       ? <>
           <div className="menu"> children </div>
           <div className="outer-area" onClick={_ => onClose()} />
         </>
       : React.null}
  </div>;
};
