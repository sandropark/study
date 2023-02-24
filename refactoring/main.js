import {statement, htmlStatement} from './statement.js';

const playsJson = `{
    "hamlet": {"name": "Hamlet", "type": "tragedy"},
    "as-like": {"name": "As You Like It", "type": "comedy"},
    "othello": {"name": "Othello", "type": "tragedy"}
}`;

const invoicesJson = `[
    {
        "customer" : "BigCo",
        "performances": [
            {
                "playID": "hamlet",
                "audience": 55
            },
            {
                "playID": "as-like",
                "audience": 35
            },
            {
                "playID": "othello",
                "audience": 40
            }
        ]
    }
]`;

const plays = JSON.parse(playsJson);
const invoices = JSON.parse(invoicesJson);

invoices.forEach(invoice => {
    console.log(statement(invoice, plays));
    console.log(htmlStatement(invoice, plays));
});