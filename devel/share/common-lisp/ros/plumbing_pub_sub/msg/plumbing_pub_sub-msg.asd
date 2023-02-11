
(cl:in-package :asdf)

(defsystem "plumbing_pub_sub-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Personal" :depends-on ("_package_Personal"))
    (:file "_package_Personal" :depends-on ("_package"))
  ))