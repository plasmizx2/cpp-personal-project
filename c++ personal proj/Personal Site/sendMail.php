<?php
if ($_SERVER["REQUEST_METHOD"] === "POST") {
    // 1. Capture form fields
    $name    = $_POST["name"];
    $email   = $_POST["email"];
    $message = $_POST["message"];

    // 2. Where do you want to receive the messages?
    //    - It can be the same domain mailbox or a personal Gmail, etc.
    //    - E.g., "sean@example.com"
    $to = "contactus@dumontdev.com";
   



    // 3. Construct email details
    $subject = $_POST["subject"]; 
    $body    = "Name: $name\n"
             . "Email: $email\n\n"
             . "Message:\n$message";

    // 4. Headers: use your domain-based email in the "From" field
    //    so your host doesn’t flag it as spam.
    $headers  = "From: contactus@dumontdev.com\r\n";
    // "Reply-To" is the visitor's email, so you can just click "Reply"
    $headers .= "Reply-To: $email\r\n";

    // 5. Send the email
    $mailSent = mail($to, $subject, $body, $headers);

    // 6. Optionally redirect to a Thank You page or echo a message
    if ($mailSent) {
        header("Location: thank_you.html");
        exit;
    } else {
        echo "Mail failed. Please try again or contact the administrator.";
    }
}
?>