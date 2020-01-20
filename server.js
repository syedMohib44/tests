const express = require('express');
const bodyParser = require('body-parser');
const app = express();
const pool = require('data/config.js');



app.get('/restraunt/:param1', function(req, res){
    let sql = 'Select * from ResturantOrders Join Orders On rest_ID ='+ req.params.param1;
    pool.query(sql, function(err, result){
        if(err) throw err;
        console.log(result);
    });
});

app.post('/add_order/:param1/:param2', function(req, res){
    pool.query('Select * from ResturantOrders Where rest_ID ='+ req.params.param1 + 'AND ord_id='+ req.params.param2, function(err, result, fields){
        if(!result){
            let data = {ord_id: req.body.ordID, ord_items, ordItems};
            let sql = 'Insert into Orders ?';
            pool.query(sql, data, function(err, order){
                if(err) throw err;
                console.log(order + ' Successfully Inserted');
            });
        }
        else{
            var totalItm = result.ord_items + req.body.ord_item;
            pool.query('Update Orders Set ord_items=' + totalItm + 'Where ord_id=' + result.ord_id, data, function(err, order){
                if(err) throw err;
                console.log(order + ' Successfully updated');
            });
        }
    });
});

app.post('/delete_order/:param1/:param2', function(req, res){
    pool.query('Select * from ResturantOrders Where rest_ID ='+ req.params.param1 + 'AND ord_id='+ req.params.param2, function(err, result, fields){
        if(result){
            pool.query('Delete * from Orders Where ord_id=' + req.params.param2, data, function(err, order){
                if(err) throw err;
                console.log(order + ' Successfully Deleted');
            });
        }
    });
});

app.listen(8000, function (){
    console.log('Server is connected');
});