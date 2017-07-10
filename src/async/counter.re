type state = {count: int, timerId: option Js.Global.intervalId};

let increaseCount _id {ReasonReact.state: state} => {
  Js.log "increasing";
  ReasonReact.Update {...state, count: state.count + 1}
};

let handleInterval update id => {
  Js.log "handling";
  update increaseCount id
};

let component = ReasonReact.statefulComponent "Counter";

let make _children => {
  ...component,
  initialState: fun () => {count: 0, timerId: None},
  didMount: fun {state, enqueue} => {
    Some (Js.Global.setInterval (handleInterval enqueue) 10000);
    handleInterval enqueue 0;
    ReasonReact.NoUpdate
  },
  render: fun {state} => <div> (ReasonReact.stringToElement (string_of_int state.count)) </div>
};
