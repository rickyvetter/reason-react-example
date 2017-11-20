type action =
  | Toggle
  | UpdateCount;

type onOff =
  | On
  | Off;
let toggle(x) = switch (x) { | On => Off | Off => On };

type state = {
  stateValue: int,
  stateSwitch: onOff
};

let component = ReasonReact.reducerComponent("Page");
let handleClick = (_event, {ReasonReact.reduce}) => {
  Js.log("clicked!");
  reduce((_) => Toggle, ());
};

let make = (_children) => {
  ...component,
  initialState: () => { stateValue: 0, stateSwitch: Off },
  reducer: (action, state) =>
    switch action {
      | Toggle =>
        ReasonReact.UpdateWithSideEffects({...state, stateSwitch: toggle(state.stateSwitch) }, ({reduce}) => reduce((_) => UpdateCount, ()))
      | UpdateCount =>
        ReasonReact.Update({...state, stateValue: state.stateValue + 1})
      },
  render: ({state, handle}) =>
    <div>
      <div onClick=(handle(handleClick))>
        <span> (ReasonReact.stringToElement("Click count: ")) </span>
        <span> (ReasonReact.stringToElement(string_of_int(state.stateValue))) </span>
      </div>
      <div>
        <span> (ReasonReact.stringToElement("Switch state: ")) </span>
        <span> (ReasonReact.stringToElement(switch (state.stateSwitch) { | On => "on" | Off => "off"})) </span>
      </div>
    </div>
};


/*
type action =
  | Toggle
  | UpdateCount;

type onOff =
  | On
  | Off;
let toggle(x) = switch (x) { | On => Off | Off => On };

type state = {
  stateValue: int,
  stateSwitch: onOff
};

let component = ReasonReact.reducerComponent("Page");
let handleClick = (_event, {ReasonReact.reduce}) => {
  Js.log("clicked!");
  reduce((_) => Toggle, ());
};

let make = (_children) => {
  ...component,
  initialState: () => {Js.log("fuuck"); { stateValue: 0, stateSwitch: Off }},
  reducer: (action, state) => {
    Js.log(action);
    switch action {
      | Toggle =>
        ReasonReact.UpdateWithSideEffects({...state, stateSwitch: toggle(state.stateSwitch) }, ({reduce}) => reduce((_) => UpdateCount, ()))
      | UpdateCount =>
        Js.log("wowsers");
        ReasonReact.Update({...state, stateValue: state.stateValue + 1})
      }
  },
  render: ({state, handle}) => {
    Js.log(state);
    <div>
      <div onClick=(handle(handleClick))>
        <span> (ReasonReact.stringToElement("Click count: ")) </span>
        <span> (ReasonReact.stringToElement(string_of_int(state.stateValue))) </span>
      </div>
      <div>
        <span> (ReasonReact.stringToElement("Switch sstate: ")) </span>
        <span> (ReasonReact.stringToElement(switch (state.stateSwitch) { | On => "on" | Off => "off"})) </span>
      </div>
    </div>
  }
};
 */
