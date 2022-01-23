let searchIcon = [%bs.raw
  {|require("../../assets/images/search-icon.svg").default|}
];

open ReactSelect;

type state = {
  isOpen: bool,
  selectedOption: option(selectOption),
};

[@react.component]
let make = (~options: array(ReactSelect.selectOption)) => {
  let (state, setState) =
    React.useState(_ => {isOpen: false, selectedOption: None});
  let openDropdown = () => setState(pre => {...pre, isOpen: true});
  let closeDropdown = () => setState(pre => {...pre, isOpen: false});
  let toggleOpen = () => setState(pre => {...pre, isOpen: !pre.isOpen});
  let onSelectChange = (option: option(selectOption)) => {
    setState(_ => {selectedOption: option, isOpen: false});
  };

  let {isOpen, selectedOption} = state;

  <Dropdown
    isOpen
    openDropdown
    closeDropdown
    target={
      <DropdownButton onClick=toggleOpen>
        {switch (selectedOption) {
         | None => React.string("Select a country")
         | Some(option) => option.value->React.string
         }}
      </DropdownButton>
    }>
    <ReactSelect
      autoFocus=true
      components={
        dropdownIndicator: () =>
          <img className="search-icon" src=searchIcon />,
        indicatorSeparator: () => React.null,
      }
      controlShouldRenderValue=false
      menuIsOpen=true
      isMulti=false
      closeMenuOnSelect=true
      onChange=onSelectChange
      options
      tabSelectsValue=false
      placeholder={React.string("Search")}
      styles={
        control: existing => {
          let newStyles =
            ReactDOM.Style.make(
              ~display="flex",
              ~flexDirection="row-reverse",
              (),
            );
          ReactDOM.Style.combine(existing, newStyles);
        },
      }
      value=selectedOption
    />
  </Dropdown>;
};
