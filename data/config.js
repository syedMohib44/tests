const pool = mysql.createPool({
    host: 'localhost',
    user: 'root',
    password: '',
    database: 'test'
});

module.exports = pool;