[@react.component]
let make =
    (
      ~target: React.element,
      ~isOpen: bool,
      ~children: React.element,
      ~openDropdown: unit => unit,
      ~closeDropdown: unit => unit,
    ) => {
  <div
    tabIndex=0
    onKeyDown={event =>
      switch (ReactEvent.Keyboard.keyCode(event)) {
      | 27 => isOpen ? closeDropdown() : ()
      | 40 => isOpen ? () : openDropdown()
      | _ => ()
      }
    }
    className="c-dropdown">
    target
    {isOpen
       ? <>
           <div className="menu"> children </div>
           <div className="outer-area" onClick={_ => closeDropdown()} />
         </>
       : React.null}
  </div>;
};
