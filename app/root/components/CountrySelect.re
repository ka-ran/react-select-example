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
  let toggleOpen = () => {
    setState(pre_state => {...pre_state, isOpen: !state.isOpen});
  };
  let onSelectChange = (option: option(selectOption)) => {
    setState(_ => {selectedOption: option, isOpen: false});
  };

  let {isOpen, selectedOption} = state;

  <Dropdown
    isOpen
    toggleDropdown=toggleOpen
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
