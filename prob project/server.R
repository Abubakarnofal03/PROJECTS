library(shiny)
library(dplyr)
library(ggplot2)
  
# Read data from CSV file
students_data <- read.csv("StudentsPerformance.csv")

# Define server logic required to analyze the data
server <- function(input, output, session) {
  
  # Define server-side functionality based on the entire data
  
  # Render a histogram of math scores
  output$math_histogram <- renderPlot({
    ggplot(students_data, aes(x = math.score)) +
      geom_histogram(binwidth = 5, fill = "red", color = "black", alpha = 1) +
      labs(title = "Math_hist", x = "Math Score", y = "Frequency") +
      theme_minimal()
  })
  
  # Render a histogram of reading scores
  output$reading_histogram <- renderPlot({
    ggplot(students_data, aes(x = reading.score)) +
      geom_histogram(binwidth = 5, fill = "green", color = "black", alpha = 1) +
      labs(title = "reading_hist", x = "reading Score", y = "Frequency") +
      theme_minimal()
  })
  
  # Histogram for writing scores
  output$writing_histogram <- renderPlot({
    ggplot(students_data, aes(x = writing.score)) +
      geom_histogram(binwidth = 5, fill = "blue", color = "black", alpha = 1) +
      labs(title = "writing_hist", x = "writing score", y = "frequency") +
      theme_minimal()
  })
  
  # Probability Distribution for math scores
  output$math_distribution <- renderPlot({
    ggplot(students_data, aes(x = math.score)) +
      geom_histogram(aes(y = ..density..), binwidth = 5, fill = "red", color = "black", alpha = 0.7) +
      stat_function(fun = dnorm, args = list(mean = mean(students_data$math.score), sd = sd(students_data$math.score)), color = "blue") +
      labs(title = "Math Probability Distribution", x = "Math Score", y = "Density") +
      theme_minimal()
  })
  # Probability Distribution for reading scores
  output$reading_distribution <- renderPlot({
    ggplot(students_data, aes(x = reading.score)) +
      geom_histogram(aes(y = ..density..), binwidth = 5, fill = "red", color = "black", alpha = 0.7) +
      stat_function(fun = dnorm, args = list(mean = mean(students_data$reading.score), sd = sd(students_data$reading.score)), color = "blue") +
      labs(title = "reading Probability Distribution", x = "reading Score", y = "Density") +
      theme_minimal()})
  # Probability Distribution for writing scores
  output$writing_distribution <- renderPlot({
    ggplot(students_data, aes(x = writing.score)) +
      geom_histogram(aes(y = ..density..), binwidth = 5, fill = "red", color = "black", alpha = 0.7) +
      stat_function(fun = dnorm, args = list(mean = mean(students_data$writing.score), sd = sd(students_data$writing.score)), color = "blue") +
      labs(title = "writing Probability Distribution", x = "writing Score", y = "Density") +
      theme_minimal()})
  
  # Regression model for math scores
  output$math_regression <- renderPlot({
    ggplot(students_data, aes(x = reading.score, y = math.score)) +
      geom_point() +
      geom_smooth(method = "lm", se = FALSE, color = "red") +
      labs(title = "Regression Model for Math Scores", x = "Reading Score", y = "Math Score") +
      theme_minimal()
  })
  
  # Regression model for reading scores
  output$reading_regression <- renderPlot({
    ggplot(students_data, aes(x = writing.score, y = reading.score)) +
      geom_point() +
      geom_smooth(method = "lm", se = FALSE, color = "green") +
      labs(title = "Regression Model for Reading Scores", x = "Writing Score", y = "Reading Score") +
      theme_minimal()
  })
  
  # Regression model for writing scores
  output$writing_regression <- renderPlot({
    ggplot(students_data, aes(x = math.score, y = writing.score)) +
      geom_point() +
      geom_smooth(method = "lm", se = FALSE, color = "blue") +
      labs(title = "Regression Model for Writing Scores", x = "Math Score", y = "Writing Score") +
      theme_minimal()
  })
  # Calculate and display mean and mode for math scores
  output$mean_mode_text_math <- renderText({
    mean_value <- mean(students_data$math.score)
    mode_value <- as.numeric(names(table(students_data$math.score)[table(students_data$math.score) == max(table(students_data$math.score))]))
    paste("Mean Math Score: ", round(mean_value, 2),
          " Mode Math Score: ", mode_value)
  })
  
  # Calculate and display mean and mode for reading scores
  output$mean_mode_text_reading <- renderText({
    mean_value <- mean(students_data$reading.score)
    mode_value <- as.numeric(names(table(students_data$reading.score)[table(students_data$reading.score) == max(table(students_data$reading.score))]))
    paste("Mean Reading Score: ", round(mean_value, 2),
          " Mode Reading Score: ", mode_value)
  })
  
  # Calculate and display mean and mode for writing scores
  output$mean_mode_text_writing <- renderText({
    mean_value <- mean(students_data$writing.score)
    mode_value <- as.numeric(names(table(students_data$writing.score)[table(students_data$writing.score) == max(table(students_data$writing.score))]))
    paste("Mean Writing Score: ", round(mean_value, 2),
          " Mode Writing Score: ", mode_value)
  })
  
  # Render a boxplot for math scores
  output$math_boxplot <- renderPlot({
    ggplot(students_data, aes(x = 1, y = math.score)) +
      geom_boxplot(fill = "red", color = "black") +
      labs(title = "Math Scores Boxplot", x = "", y = "Math Score") +
      theme_minimal()
  })
  
  # Render a boxplot for reading scores
  output$reading_boxplot <- renderPlot({
    ggplot(students_data, aes(x = 1, y = reading.score)) +
      geom_boxplot(fill = "green", color = "black") +
      labs(title = "Reading Scores Boxplot", x = "", y = "Reading Score") +
      theme_minimal()
  })
  
  # Render a boxplot for writing scores
  output$writing_boxplot <- renderPlot({
    ggplot(students_data, aes(x = 1, y = writing.score)) +
      geom_boxplot(fill = "blue", color = "black") +
      labs(title = "Writing Scores Boxplot", x = "", y = "Writing Score") +
      theme_minimal()
  })
  #scatter plot for male and female
  output$scatter_plot <- renderPlot({
    ggplot(students_data, aes(x = reading.score, y = writing.score, color = gender)) +
      geom_point() +
      labs(title = "Reading Scores vs. Writing Scores", x = "Reading Score", y = "Writing Score", color = "Gender") +
      theme_minimal()
  })
  
}

