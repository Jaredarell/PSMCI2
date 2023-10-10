const ctx1 = document.getElementById("myChart").getContext('2d');
const printCharts = () => {
    renderModelChart()
}

const renderModelChart = () => {
    const data = {
        labels: ["13:00", "15:00", "17:00", '19:00', '21:00'],
        datasets: [{
            label: "Niveles de lectura",
            data: [10,11,30, 5, 19]

        }]
    }
    const humity = {
        labels: ["13:00", "15:00", "17:00", '19:00', '21:00'],
        datasets: [{
            label: "Niveles de humedad",
            data: [13,15,20, 2, 1]

        }]
    }
    new Chart('modelschart', {type: 'line', data})
    new Chart('modelschartTwo', {type: 'line', data})
}

printCharts()

const area = ["13:00", "15:00", "17:00", '19:00', '21:00']
const temperature = [19.4, 27.3, 50.9, 37.5, 12.1]

const myChart = new Chart(ctx1, {
    type: "line",
    data: {
        labels: ["13:00", "15:00", "17:00", '19:00', '21:00'],
        datasets: [{
            label: "temperatura",
            data: temperature,
            backgroundColor:[
                "rgba(255, 99, 132, 0.2)",
                "rgba(54, 162, 235, 0.2)",
                "rgba(75, 192, 192, 0.2)",
                "rgba(153, 102, 255, 0.2)",
            ],
            borderColor:[
                "rgba(255, 99, 132, 1)",
                "rgba(54, 162, 235, 1)",
                "rgba(75, 192, 192, 1)",
                "rgba(153, 102, 255, 1)",
            ]

        }],
        borderWidth: 1.5
    }
})
