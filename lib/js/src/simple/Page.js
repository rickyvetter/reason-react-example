'use strict';

var Block       = require("bs-platform/lib/js/block.js");
var Curry       = require("bs-platform/lib/js/curry.js");
var React       = require("react");
var Pervasives  = require("bs-platform/lib/js/pervasives.js");
var ReasonReact = require("reason-react/lib/js/src/ReasonReact.js");

function toggle(x) {
  if (x !== 0) {
    return /* On */0;
  } else {
    return /* Off */1;
  }
}

var component = ReasonReact.reducerComponent("Page");

function handleClick(_, param) {
  console.log("clicked!");
  return Curry._2(param[/* reduce */1], (function () {
                return /* Toggle */0;
              }), /* () */0);
}

function make() {
  var newrecord = component.slice();
  newrecord[/* render */9] = (function (param) {
      var state = param[/* state */2];
      var match = state[/* stateSwitch */1];
      return React.createElement("div", undefined, React.createElement("div", {
                      onClick: Curry._1(param[/* handle */0], handleClick)
                    }, React.createElement("span", undefined, "Click count: "), React.createElement("span", undefined, Pervasives.string_of_int(state[/* stateValue */0]))), React.createElement("div", undefined, React.createElement("span", undefined, "Switch state: "), React.createElement("span", undefined, match !== 0 ? "off" : "on")));
    });
  newrecord[/* initialState */10] = (function () {
      return /* record */[
              /* stateValue */0,
              /* stateSwitch : Off */1
            ];
    });
  newrecord[/* reducer */12] = (function (action, state) {
      if (action !== 0) {
        return /* Update */Block.__(0, [/* record */[
                    /* stateValue */state[/* stateValue */0] + 1 | 0,
                    /* stateSwitch */state[/* stateSwitch */1]
                  ]]);
      } else {
        return /* UpdateWithSideEffects */Block.__(3, [
                  /* record */[
                    /* stateValue */state[/* stateValue */0],
                    /* stateSwitch */toggle(state[/* stateSwitch */1])
                  ],
                  (function (param) {
                      return Curry._2(param[/* reduce */1], (function () {
                                    return /* UpdateCount */1;
                                  }), /* () */0);
                    })
                ]);
      }
    });
  return newrecord;
}

exports.toggle      = toggle;
exports.component   = component;
exports.handleClick = handleClick;
exports.make        = make;
/* component Not a pure module */
