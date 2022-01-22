type selectOption = {
  value: string,
  label: React.element,
};

type replaceableComponents = {
  [@bs.as "DropdownIndicator"]
  dropdownIndicator: unit => React.element,
  [@bs.as "IndicatorSeparator"]
  indicatorSeparator: unit => React.element,
  /*    [@bs.as "ClearIndicator"]
           clearIndicator: unit => React.element,
         [@bs.as "Input"]
        input: (~onChange: ReactEvent.Form.t => unit) => React.element, */
};

type styles = {control: ReactDOM.Style.t => ReactDOM.Style.t};

[@bs.module "react-select"] [@react.component]
external make:
  (
    ~autoFocus: option(bool)=?,
    ~components: option(replaceableComponents)=?,
    ~controlShouldRenderValue: option(bool)=?,
    ~menuIsOpen: option(bool)=?,
    ~isMulti: bool,
    ~closeMenuOnSelect: option(bool)=?,
    ~onChange: option(selectOption) => unit,
    ~options: array(selectOption),
    ~placeholder: option(React.element)=?,
    ~value: option(selectOption),
    ~styles: option(styles)=?
  ) =>
  React.element =
  "default";
